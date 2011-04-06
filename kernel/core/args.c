/*
 * vim:tabstop=4
 * vim:noexpandtab
 *
 * Kernel Argument Parser
 */
#include <system.h>

void
parse_args(char * arg) {
	if (!arg) { return; }
	char * pch;
	char * cmd;
	char * save;
	pch = strtok_r(arg," ",&save);
	cmd = pch;
	if (!cmd) { return; }
	char * argv[1024]; /* Command tokens (space-separated elements) */
	int tokenid = 0;
	while (pch != NULL) {
		argv[tokenid] = (char *)pch;
		++tokenid;
		pch = strtok_r(NULL," ",&save);
	}
	argv[tokenid] = NULL;
	for (int i = 0; i < tokenid; ++i) {
		if (!strcmp(argv[i],"vid=qemu")) {
			/* QEMU Video Mode, we are free to set things for 1024x768 */
			graphics_install_bochs();
			ansi_init(&bochs_write, 128, 64);
		}
	}
}
