regiond
=======

Region locks are annoying. Most of them are also IP-based, and very easy to bypass - with a caveat: you normally end up tunneling your entire connection for as long as they need to pretend to be in another country, and then disable it again when you're done.

This has numerous consequences, including:

* Flicking a VPN on or off normally resets the primary network interface or otherwise disconnects all active connections - this is especially troublesome for non-Torrent downloads and IRC
* Quite a few online services (Google, for instance) will get paranoid if you suddenly access your account from the other side of the planet
* Sending *everything* over a tunnel means *everything* has to be redirected and encrypted, which slows everything down and puts extra load on your CPU (and battery, if you're on a laptop)
* You can only dodge one lock at a time - if you're in the US and want to do something restricted to Japan, you can't do anything restricted to the US at the same time

A little known fact is that none of this actually has to happen. It's entirely possible to selectively route packets over various kinds of tunnels, and leave everything else alone. The problem is, it takes quite a bit of tinkering and monitoring to set up, and is far beyond the average user's capability.

Editing a routing table or selectively proxying request isn't hard, nor particularly advanced. It's repetitive, boring and time-consuming - and that sort of thing was exactly what computers were invented for in the first place.

*Someone* just has to write a program that does it.

Goals
-----
* Cross-Platform (see below for target platforms)
* A small service (Windows) or daemon (everything else) runs in the background and handles it all
    * This service must never drag attention to itself in any way, including by slowing down the user's computer noticeably
* Dodgable region locks are described by configuration files
    * The whole process has to be transparent - once you install a lock description file, the lock should essentially disappear without a trace
* Configuration is done by opening `localhost:9999` (configurable) in a web browser
    * If something is already running on port 9999, it will fall back to 8888, 7777, 6666, etc. until it finds an unoccupied one

Target Platforms
----------------
* Windows Vista/7/8
    * Windows XP may be added if there is demand for it, but it's on low priority mainly due to how difficult parts of this will be to get working without some of Vista's new APIs
* Mac OS X 10.8+
    * 10.7 may be added if there's demand for it, but we need testers in that case
    * 10.6 is the same, but that would bring [deployment complications](http://stackoverflow.com/a/14494515/386580)
* Linux
    * Targeting Ubuntu 13.10/Mint 16 and up-to-date Arch Linux

Technical Details
-----------------
`regiond` (obviously named after the "Region" in "Region Lock" and the "d" suffix usually given to Unix daemons) is written in C++, as it's a powerful language capable of low-level operations and low resource usage.  
It currently uses the Poco framework, mainly for the `Poco::Util::ServerApplication` class, which makes crossplatform background processes easy, by smoothing out the differences between a Windows Service and an Unix Daemon.

To avoid region locks, it will feature at least two modes of operation: **Tor** and **OpenVPN**.

### Tor
The simplest way to bypass a region lock is by using Tor. The program can manage multiple Tor instances as subprocesses, one for each country you want to pretend to be in - all configured to favor speed over security (one hop is enough to dodge a region lock; we're not fighting governments here) and to restrict exit nodes to only the allowed region - and uses a built-in SOCKS5 proxy server to dispatch requests to the appropriate one, or just pass the request through if it doesn't match any rules.

The most clear benefit of this is that Tor runs entirely in userspace. There are no kernelspace components involved, which means that installation doesn't require administrator/root privileges.  
The drawback is that it's slow. Annoyingly slow. It's also quite easy to blacklist the entire Tor network, which limits its usability in some cases.

To use the Tor method, the system's (or at least the used application's) proxy must be set to whatever port the proxy is listening on. This has some implications for the required stability of the application, as a dead or malfunctioning proxy will hamper the usability of either the target application or the entire system's network. This is the main reason why regiond *must not crash or lag*, ever, or it will start to interfere with traffic it shouldn't even touch.

As an additional bonus, running a proxy will make it possible to detect which process owns a connecting socket and filter on that. I'm not sure if this is wise though - names are unreliable things, and I can't see this working with other filter methods.

### OpenVPN
When Tor isn't good enough, there is OpenVPN to the rescue. Similarly to Tor, OpenVPN instances are ran in Subprocesses, but instead of using a proxy, regiond will here manipulate the system's routing table. This is a rather complicated setup that will ensure that only traffic to certain IPs will go over the VPN's separate network interface.

The biggest advantage of OpenVPN is that it's blazing fast, shortly followed by how reliable it is. The biggest disadvantage is that it installs drivers/kernel modules, and will require the user to install it manually, but other than that, it's superior to Tor in almost every way imaginable.  
If we also integrate [VPNGate](http://vpngate.net/) or similar, it's possible to make it easy to select a country and not worry about it anymore.

On the implementation side, this will mean a lot of quite complex platform-specific code to manipulate the routing table, and will thus have to wait until after the Tor interface is finished.
