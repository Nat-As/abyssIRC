# AnubyssIRC
[![Build Status](https://travis-ci.com/Nat-As/anubyssIRC.svg?branch=master)](https://travis-ci.com/Nat-As/anubyssIRC)

Internet Relay Chat server Daemon
(IRCD)
## Overview
This IRC Daemon is made to run on several machines that are connected to the internet. Each server exists for the execution of two tasks, the first is the relaying of messages across channels. The second is to accept commands from the controller. Commands sent by the controller are directly passed from the server to the host machines kernel, allowing the full configuration of a server device.

### References
Server loop: https://ncona.com/2019/04/building-a-simple-server-with-cpp/
<BR>
Zombie loop: https://en.wikipedia.org/wiki/Zombie_process
<BR>
<img src="https://github.com/Nat-As/anubyssIRC/tree/master/img/scrn.png" alt="screenshot"/>
