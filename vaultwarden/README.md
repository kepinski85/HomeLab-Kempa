# Vaultwarden (Bitwarden Self-Hosted Password Manager)

This directory contains a self-hosted Vaultwarden instance deployed in my homelab using Docker Compose on a Proxmox LXC Ubuntu container.

## What it does

Vaultwarden is a lightweight, self-hosted password manager — an alternative to Bitwarden cloud, with full control and privacy.

### How to deploy

```bash
cd /opt/vaultwarden
docker compose down
rm -rf ./data/*
docker compose pull
docker compose up -d
```
#### Config

Ports: 8222:80
Data Volume: ./data:/data
WebSocket Support: enabled
Signups: allowed by default (can be disabled later)

##### Notes

Version used: vaultwarden/server:1.30.5 (for stable integrated frontend)
Admin panel and advanced settings can be enabled with an environment variable (not used yet)
