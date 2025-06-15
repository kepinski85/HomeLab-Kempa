This project uses a Raspberry Pi and Arduino to collect environmental sensor data and visualize it in Grafana via InfluxDB.  
The system runs 24/7 and continuously logs readings from sensors for analysis.


## Hardware
**Raspberry Pi 4** running Raspberry Pi OS
- **Arduino UNO** connected via USB (Serial)
- **Sensors:**
  - BME280 – temperature, humidity, pressure
  - MQ135 – air quality (via analog voltage)
  - HC-SR04 – distance (ultrasonic)
- **(optional)** LCD 16x2 or OLED I2C display

## Folder Structure
kempa_lab/
├── docker-compose.yml # InfluxDB + Grafana containers
├── pi/ # Python: data receiver and logger
│ ├── serial_reader.py
│ ├── serial.log
│ ├── error.log
│ └── data_log.csv
├── arduino/ # Arduino code
│ └── sensors.ino
├── systemd/ # systemd service unit
│ └── kempa_reader.service
└── README.md # This file

## How It Works

1. **Arduino** reads sensor data and sends JSON over USB serial.
2. **Python script** on Raspberry Pi reads the serial input and:
   - Logs to CSV
   - Pushes data into InfluxDB
3. **Grafana** displays the data using a custom dashboard.

---

##  Python Setup

Inside `pi/` folder:

```bash
python3 -m venv venv
source venv/bin/activate
pip install pyserial requests
```

## Service unit to keep the logger running in background:
# /etc/systemd/system/kempa_reader.service
[Unit]
Description=Serial reader for Kempa Lab
After=network.target

[Service]
ExecStart=/home/kempa/kempa_lab/venv/bin/python /home/kempa/kempa_lab/pi/serial_reader.py
WorkingDirectory=/home/kempa/kempa_lab/pi
StandardOutput=append:/home/kempa/kempa_lab/pi/serial.log
StandardError=append:/home/kempa/kempa_lab/pi/error.log
Restart=always
User=kempa

[Install]
WantedBy=multi-user.target

## Grafana dashboard fetches data from InfluxDB (kempa database). Data is structured in JSON with fields like:

{
  "temp": 24.76,
  "hum": 87.74,
  "press": 702.05,
  "gas": 3.75,
  "dist": 141.47,
  "air_status": "Poor"
}

## To-Do / Future Improvements

    Switch to OLED I2C display (simpler wiring)

    Add enclosure for sensor modules

    Integrate alert thresholds in Grafana

    Add Prometheus or Node-RED integration
