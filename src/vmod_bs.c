#include <beanstalk.h>
#include <string.h>
#include <stdio.h>

#include <stdlib.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"

#include "vcc_if.h"

int init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
	return (0);
}

void vmod_put(struct sess *sp, const char *message)
{
	char msg[1024];
        int id, socket = bs_connect("127.0.0.1", 11300);

	strcpy(msg, message);
        id = bs_put(socket, 0, 0, 60, msg, strlen(msg));
	bs_disconnect(socket);

	return;
}
