#include "spdk/stdinc.h"

#include "spdk/nvme.h"
#include "spdk/env.h"

static struct spdk_nvme_ns *g_ns = NULL;
struct ns_entry {
	struct spdk_nvme_ctrlr *ctrlr;
};
static struct ns_entry *g_ctrlr;

static void
register_ns(struct spdk_nvme_ctrlr *ctrlr, struct spdk_nvme_ns *ns)
{
	g_ctrlr = malloc(sizeof(struct ns_entry));
	if (g_ctrlr == NULL) {
		perror("ns_entry malloc");
		exit(1);
	}
	g_ctrlr->ctrlr = ctrlr;
	g_ns = ns;
	printf("Namespace ID: %d with Size: %juGB\n", spdk_nvme_ns_get_id(ns),
	       spdk_nvme_ns_get_size(ns) / 1000000000);
}

static void
write_complete(void *arg, const struct spdk_nvme_cpl *completion)
{
	printf("Write complete\n");
}

static void
read_complete(void *arg, const struct spdk_nvme_cpl *completion)
{
	char *buf = arg;
	printf("Read complete\n");
	printf("%s", buf);
}

static bool
probe_cb(void *cb_ctx, const struct spdk_nvme_transport_id *trid,
	 struct spdk_nvme_ctrlr_opts *opts)
{
	return true;
}

static void
attach_cb(void *cb_ctx, const struct spdk_nvme_transport_id *trid,
	  struct spdk_nvme_ctrlr *ctrlr,
	  const struct spdk_nvme_ctrlr_opts *opts)
{
	int nsid, num_ns;
	struct spdk_nvme_ns *ns;
	printf("Attached to %s\n", trid->traddr);

	num_ns = spdk_nvme_ctrlr_get_num_ns(ctrlr);
	for (nsid = 1; nsid <= num_ns; nsid++) {
		ns = spdk_nvme_ctrlr_get_ns(ctrlr, nsid);
		if (ns == NULL) {
			continue;
		}
		register_ns(ctrlr, ns);
	}
}

static void
run_demo(void)
{
	struct spdk_nvme_ns *ns = g_ns;
	struct spdk_nvme_qpair *qpair;
	struct spdk_nvme_ctrlr *ctrlr = g_ctrlr->ctrlr;
	char *buf;
	int rc;
	qpair = spdk_nvme_ctrlr_alloc_io_qpair(ctrlr, NULL, 0);
	if (qpair == NULL) {
		printf("ERROR: spdk_nvme_ctrlr_alloc_io_qpair() failed\n");
		return;
	}
	buf = spdk_zmalloc(0x1000, 0x1000, NULL, SPDK_ENV_SOCKET_ID_ANY, SPDK_MALLOC_DMA);
	if (buf == NULL) {
		printf("ERROR: write buffer allocation failed\n");
		return;
	}
	snprintf(buf, 0x1000, "%s", "It's a demo.\n");
	rc = spdk_nvme_ns_cmd_write(ns, qpair, buf, 0, 1, write_complete, NULL, 0);
	if (rc != 0) {
		fprintf(stderr, "starting write I/O failed\n");
		exit(1);
	}
	rc = spdk_nvme_ns_cmd_read(ns, qpair, buf, 0, 1, read_complete, (void *)buf, 0);
	if (rc != 0) {
		fprintf(stderr, "starting read I/O failed\n");
		exit(1);
	}
	spdk_nvme_qpair_process_completions(qpair, 0);
	spdk_nvme_ctrlr_free_io_qpair(qpair);
}

int
main(void)
{
	struct spdk_env_opts opts;
	spdk_env_opts_init(&opts);
	if (spdk_env_init(&opts) < 0) {
		fprintf(stderr, "Unable to initialize SPDK env\n");
		return 1;
	}
	spdk_nvme_probe(NULL, NULL, probe_cb, attach_cb, NULL);
	run_demo();
	return 0;
}
