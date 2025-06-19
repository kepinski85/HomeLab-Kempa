# Pi-hole Setup on Raspberry Pi 4

This service provides DNS-level ad blocking for the entire home network. It runs on a Raspberry Pi 4 (Bookworm) and filters traffic using a set of curated blocklists and regex filters.

---

## Key Information

- **Device**: Raspberry Pi 4
- **IP**: `192.168.0.249` (reserved via DHCP)
- **Upstream DNS**: Quad9 (9.9.9.9 and 149.112.112.112)
- **Static role**: Primary DNS resolver for entire LAN (via router DHCP)
- **Pi-hole Version**: [latest stable]

---

##  Configuration Summary

- Raspberry Pi connected via Ethernet, DHCP reservation set in Archer router
- DNS redirection enforced via iptables (UDP & TCP port 53 → 192.168.0.249)
- Regex filters block common ad/tracker domains
- Multiple blocklists aggregated and updated with `pihole -g`

---

## Blocklists used

https://raw.githubusercontent.com/StevenBlack/hosts/master/hosts
https://dbl.oisd.nl/
https://adaway.org/hosts.txt
https://raw.githubusercontent.com/Perflyst/PiHoleBlocklist/master/android-tracking.txt
https://raw.githubusercontent.com/Perflyst/PiHoleBlocklist/master/SmartTV.txt
https://raw.githubusercontent.com/notracking/hosts-blocklists/master/hostnames.txt

- StevenBlack unified host file
- OISD full blocklist
- AdAway mobile ad domains
- SmartTV and Android telemetry domains
- notracking/hostnames

---

##  Regex Rules

Manually added via GUI → *Group Management → Domain Management → Regex*:

```regex
(^|\.)doubleclick\.net$
(^|\.)googlesyndication\.com$
(^|\.)adnxs\.com$
(^|\.)samsungads\.com$
(^|\.)smartclip\.net$

```

## Next steps

Monitor new domains in Query Log and expand regex

Optionally add Unbound as local resolver

Add monitoring via Prometheus or Netdata


