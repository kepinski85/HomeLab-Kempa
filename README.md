# HomeLab-Kempa

This repository documents my journey in building a complete self-managed homelab. The project serves both as a personal infrastructure environment and as a learning platform to improve my skills in system administration, DevOps, networking, and cybersecurity.

## Objectives

- Host private and family-accessible services (cloud storage, websites, VPN)
- Learn and implement modern infrastructure management (Proxmox, Docker, reverse proxy)
- Simulate real production-like environments
- Practice cyber defense and offensive skills

## Hardware Overview

| Device          | Role                                  |
|----------------|----------------------------------------|
| Raspberry Pi 4 | Sensor platform, light services        |
| PC (Hi-end)     | Daily driver                           |
| Old PC         | Proxmox hypervisor                     |
| MacBook w/ Kali | Pentesting / OSINT                    |
| Archer C6 Router | Main gateway for the network         |

## Network Topology

ISP Router → TP-Link Archer C6 → Unmanaged Switch → [PC, RPi4, Old PC]  
Wi-Fi: MacBook (Kali)

Diagram: `assets/topology.png` (to be added)

## Project Phases

- [x] Phase 0: Initialize Git repository and documentation
- [ ] Phase 1: Install and configure Proxmox VE
- [ ] Phase 2: Deploy core services (Pi-hole, Nextcloud, VPN)
- [ ] Phase 3: Set up reverse proxy with HTTPS support
- [ ] Phase 4: Add monitoring and logging stack
- [ ] Phase 5: Build public documentation page/portfolio

## Weekly Plan - Week 1: Foundation Setup

| Day | Task                                                         | Notes                  |
|-----|--------------------------------------------------------------|------------------------|
| 1   | Install Proxmox VE on the old PC                             | `proxmox/install.md`   |
| 2   | Configure repositories and update the system                 | `proxmox/config.md`    |
| 3   | Connect external storage (RPi NAS via NFS/Samba)             | `storage/mount.md`     |
| 4   | Deploy Pi-hole in LXC container                              | `services/pihole.md`   |
| 5   | Set up static IPs and local DNS via Pi-hole                  | `network/dns.md`       |
| 6   | Deploy and test VPN access (WireGuard)                       | `services/vpn.md`      |
| 7   | Push updates to GitHub and publish a short status update     | `README.md`            |

## Directory Structure (planned)
homelab-kempexor/
├── README.md
├── proxmox/
│ ├── install.md
│ └── config.md
├── services/
│ ├── pihole.md
│ ├── nextcloud.md
│ └── vpn.md
├── network/
│ └── topology.md
├── storage/
│ └── mount.md
└── assets/
  └── topo.png
## Notes

All configurations will be documented as plain-text walkthroughs to reflect real-world thinking and debugging.
This repository will grow over time into a complete homelab knowledge base and demonstration of my practical skills.
