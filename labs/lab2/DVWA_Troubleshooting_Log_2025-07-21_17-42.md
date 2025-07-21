# DVWA Lab Troubleshooting Log

**Date:** 2025-07-21 17:42:55
**System:** Kali Linux (VM)  
**Setup:** DVWA with dual network adapters (NAT + Host-Only)  
**Proxy Tool:** Burp Suite  
**Browser:** Firefox

---

## 🔧 Issues and Fixes

### 1. Unable to Connect to Google.com / No Internet

- **Symptom:** `ping google.com` → `Temporary failure in name resolution`
- **Diagnosis:** DNS issue or no IP via DHCP
- **Fix:**
  - Use `sudo dhclient eth0`
  - Verify `/etc/resolv.conf` contains:
    
    ```
    nameserver 8.8.8.8
    nameserver 1.1.1.1
    ```
  - If error `cannot create /etc/resolv.conf`, ensure you're not using immutable configs or bind-mounted files (common in WSL or restricted distros)

---

### 2. DVWA Not Loading on Firefox

- **Symptom:** `dvwa.local` not resolving or site not opening
- **Diagnosis:** Host mapping or Apache not running
- **Fix:**
  - Add `127.0.0.1 dvwa.local` to `/etc/hosts`
  - Ensure Apache is listening: `sudo ss -tupln | grep apache`
  - Start/restart Apache: `sudo service apache2 start`

---

### 3. DVWA MySQL Connection Error

- **Error Message:**
  
  ```
  Fatal error: Uncaught mysqli_sql_exception: Connection refused in dvwaPage.inc.php
  ```
- **Fix:** Start MariaDB
  
  ```
  sudo service mariadb start
  ```

---

### 4. Burp Suite Not Intercepting DVWA Requests

- **Symptom:** Burp shows traffic from example.com but not DVWA
- **Diagnosis:** Proxy not properly routing DVWA requests
- **Fix:**
  - Use **Option B**:
    - Firefox → Preferences → Network Settings:
      - Manual proxy: `127.0.0.1`, Port: `8080`
      - Add `127.0.0.1,localhost` to **No Proxy For**
  - Ensure **Intercept is ON** in Burp Suite
  - Trust Burp Certificate if needed

---

### 5. Delayed DHCP/IP Assignment

- **Symptom:** Internet unavailable for a few minutes after VM boot
- **Diagnosis:** dhclient takes time to assign IP
- **Fix:** Wait or run:
  
  ```
  sudo dhclient eth0
  ```

---

### 6. Firefox Won’t Load DVWA While Burp Intercepts

- **Diagnosis:** Interception rules block too many request types
- **Fix:** Tune Burp → Proxy → Interception Rules
  - Allow basic GET/POST only
  - Disable image/script filters if blocking important content

---

## ✅ Current Working Configuration

| Component   | Status                      |
| ----------- | --------------------------- |
| NAT Adapter | ✅ Online (Internet working) |
| Host-Only   | ✅ Connects to DVWA          |
| Apache      | ✅ Running                   |
| MariaDB     | ✅ Running                   |
| Burp Suite  | ✅ Intercepts via Option B   |
| Firefox     | ✅ Connected to DVWA         |

---

## ✅ Tips for Stability

- Always start MariaDB and Apache at boot (can be automated).
- Use consistent Host-Only IP range (e.g., `192.168.56.x`).
- Keep `/etc/hosts` updated for any local domains.
- Monitor `resolv.conf` if using VM snapshots or templates.

---
