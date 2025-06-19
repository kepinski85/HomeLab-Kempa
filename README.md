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

Topology: topo.png

## Project Phases

- [ ] Phase 0: Initialize Git repository and documentation
- [x] Phase 1: Install and configure Proxmox VE
- [ ] Phase 2: Deploy core services (Pi-hole, Nextcloud, VPN)
- [ ] Phase 3: Set up reverse proxy with HTTPS support
- [ ] Phase 4: Add monitoring and logging stack
- [ ] Phase 5: Build public documentation page/portfolio

## Plan
| Service        | Description                                      | Location                     |
|----------------|--------------------------------------------------|------------------------------|
| ✅ Vaultwarden | Self-hosted Bitwarden-compatible password manager | [`vaultwarden/`](./vaultwarden) |
| ⏳ Coming soon | Monitoring (Netdata / Grafana / Prometheus)     | `monitoring/`                |
| ⏳ Coming soon | VPN (WireGuard / Tailscale)                     | `vpn/`                       |
| ⏳ Coming soon | DNS sinkhole (Pi-hole / AdGuardHome)            | `pihole/`                    |
| ⏳ Coming soon | Reverse proxy + SSL (Caddy / Nginx Proxy Manager) | `proxy/`                   |
| ⏳ Coming soon | File storage & sync (Nextcloud / Syncthing)     | `cloud/`        


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
└── topo.png
├── vaultwarden
| └── docker-compose.yml
| └── README.md

## Skills in Progress

- Linux administration (RHCSA in progress)
- Python scripting (via Codecademy)
- Cybersecurity & pentesting (TryHackMe / OverTheWire)
- Networking, DNS, and firewalling
- Docker, Proxmox, containers, and self-hosting
- Infrastructure documentation and GitOps

## Notes

Configured Pi-hole service, please check pihole.md for further details
All configurations will be documented as plain-text walkthroughs to reflect real-world thinking and debugging.
This repository will grow over time into a complete homelab knowledge base and demonstration of my practical skills.
Added Arduino folder where I made little side project to monitoring lab room parameters
