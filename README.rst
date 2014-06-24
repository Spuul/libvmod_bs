============
vmod_bs
============

-------------------------
Varnish Beanstalkd Module
-------------------------

:Author: Daniel Muller
:Date: 2011-06-24
:Version: 0.1
:Manual section: 3

SYNOPSIS
========

import bs;

DESCRIPTION
===========

Varnish vmod to put a message into beanstlakd daemon

FUNCTIONS
=========

put
---

Prototype
        ::

                put(STRING S)
Return value
	VOID
Description
	Puts a message into the Beanstalkd queue
Example
        ::

                bs.put("message string");

INSTALLATION
============

Dependencies::

 https://github.com/deepfryed/beanstalk-client.git

Usage::

 ./autogen.sh
 ./configure VARNISHSRC=DIR [VMODDIR=DIR]
 make
 make install

`VARNISHSRC` is the directory of the Varnish source tree for which to
compile your vmod. Both the `VARNISHSRC` and `VARNISHSRC/include`
will be added to the include search paths for your module.

Optionally you can also set the vmod install directory by adding
`VMODDIR=DIR` (defaults to the pkg-config discovered directory from your
Varnish installation).

Make targets:

* make - builds the vmod
* make install - installs your vmod in `VMODDIR`
* make check - runs the unit tests in ``src/tests/*.vtc``

In your VCL you could then use this vmod along the following lines::
        
        import bs;

        sub vcl_deliver {
                bs.put("Message string");
        }

HISTORY
=======

COPYRIGHT
=========

