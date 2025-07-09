# 🔐 Lab 2: Web Application Testing Environment Setup (DVWA on Kali)

---

## 🎯 Objective

Set up a local web application testing environment using **DVWA** (Damn Vulnerable Web App) on **Kali Linux**, and resolve real-world networking issues during installation.

---

## 🛠️ Environment Details

| Component        | Configuration                     |
|------------------|----------------------------------|
| Attacker Machine | Kali Linux (VirtualBox VM)       |
| Target App       | DVWA installed locally on Kali   |
| Network Mode     | Adapter 1: NAT (Internet)        |
|                  | Adapter 2: Host-only (Lab comm)  |

---

## 🧪 Key Tools

- `apache2` — Web server
- `mariadb-server` — Database
- `php` — Scripting engine
- `git` — To clone DVWA from GitHub

---

## 🚧 Issues Encountered & Fixes Applied

### ❌ Issue 1: `apt` failing with `Temporary failure resolving 'http.kali.org'`

**Root Cause:**  
Kali's `eth0` (NAT interface) had no IP or default gateway.

**Fix Applied:**  
Manually assigned IP and gateway:

```bash
sudo ip addr add 10.0.2.15/24 dev eth0
sudo ip link set eth0 up
sudo ip route add default via 10.0.2.2 dev eth0
echo "nameserver 8.8.8.8" | sudo tee /etc/resolv.conf
```

---

### ❌ Issue 2: `dhclient` command not found

**Fix Applied:**  
Used manual `ip` commands to configure networking.

---

### ❌ Issue 3: MySQL not running (`Can't connect to local server through socket`)  

**Fix Applied:**  
```bash
sudo systemctl start mariadb
```

---

### ❌ Issue 4: DVWA shows white screen after setup

**Fix Applied:**  
Enabled PHP error reporting in `config.inc.php`:

```php
ini_set('display_errors', 1);
error_reporting(E_ALL);
```

---

### ❌ Issue 5: DVWA user login fails (`Access denied for user 'dvwa'@'localhost'`)

**Fix:**  
DVWA expects DB user to be `dvwa`, but created user was `dvwauser`.

🔧 Updated `/var/www/html/DVWA/config/config.inc.php`:

```php
$_DVWA['db_user'] = 'dvwauser';
$_DVWA['db_password'] = 'password';
```

---

## ✅ Installation Steps for DVWA

```bash
sudo apt update
sudo apt install apache2 mariadb-server php php-mysqli git -y

cd /var/www/html
sudo git clone https://github.com/digininja/DVWA.git
cd DVWA
sudo cp config/config.inc.php.dist config/config.inc.php
sudo nano config/config.inc.php
```

MariaDB setup:
```sql
CREATE DATABASE dvwa;
CREATE USER 'dvwauser'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON dvwa.* TO 'dvwauser'@'localhost';
FLUSH PRIVILEGES;
```

Start services:
```bash
sudo systemctl start apache2
sudo systemctl start mariadb
sudo systemctl enable apache2
sudo systemctl enable mariadb
```

DVWA setup in browser:
```
http://localhost/DVWA/setup.php
```

Login with: `admin` / `password`

---

## ✅ Outcome

DVWA is successfully installed and accessible. You are now ready to begin attacking and analyzing web application vulnerabilities.

---

## 📁 Folder Structure

```
labs/
└── Lab2-DVWA-Setup/
    ├── README.md
    ├── screenshots/
    └── notes.md
```

---

**Lab completed on:** 2025-07-09
