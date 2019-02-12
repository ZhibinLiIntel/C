#include "spdk/stdinc.h"
#include "spdk/nvme.h"

static void
print_ascii_string(const void *buf, size_t size)
{
	const char *str = buf;
	while (size > 0 && str[size - 1] == ' ') {
		size--;
	}
	while (size--) {
		if (*str >= 0x20 && *str <= 0x7E) {
			printf("%c", *str);
		} else {
			continue;
		}
		str++;
	}
	printf("\n");
}

static bool
probe_cb(void *cb_ctx, const struct spdk_nvme_transport_id *trid,
	 struct spdk_nvme_ctrlr_opts *opts)
{
	return true;
}

static void
print_info(struct spdk_nvme_ctrlr *ctrlr)
{
	const struct spdk_nvme_ctrlr_data *cdata;
	cdata = spdk_nvme_ctrlr_get_data(ctrlr);
	printf("Model Number: ");
	print_ascii_string(cdata->mn, sizeof(cdata->mn));
}

static void
attach_cb(void *cb_ctx, const struct spdk_nvme_transport_id *trid,
	  struct spdk_nvme_ctrlr *ctrlr,
	  const struct spdk_nvme_ctrlr_opts *opts)
{
	print_info(ctrlr);
}

int main(void)
{
	struct spdk_env_opts opts;
	spdk_env_opts_init(&opts);

	if (spdk_env_init(&opt) < 0) {
		fprintf(stderr, "Unable to initialize SPDK env\n");
		return 1;
	}
	spdk_nvme_probe(NULL, NULL, probe_cb, attach_cb, NULL);
	return 0;
}
