#!/bin/bash

SERVICE_NAME=npmdev
WORKING_DIR="/home/pi/Downloads"
SERVICE_FILE="/etc/systemd/system/${SERVICE_NAME}.service"

echo "?? Creating systemd service: $SERVICE_NAME"

# Check if target directory exists
if [ ! -d "$WORKING_DIR" ]; then
    echo "Directory $WORKING_DIR does not exist, please verify the project path!"
    exit 1
fi

# Create systemd service file
sudo tee "$SERVICE_FILE" > /dev/null <<EOF
[Unit]
Description=Start npm dev server on boot
After=network.target

[Service]
ExecStart=/bin/bash -c 'cd ${WORKING_DIR} && npm run dev'
WorkingDirectory=${WORKING_DIR}
User=pi
Restart=always
Environment=PATH=/usr/bin:/usr/local/bin
Environment=NODE_ENV=production

[Install]
WantedBy=multi-user.target
EOF

# Reload systemd and enable service
echo "Reloading systemd and enabling service..."
sudo systemctl daemon-reexec
sudo systemctl daemon-reload
sudo systemctl enable "$SERVICE_NAME"
sudo systemctl start "$SERVICE_NAME"

# Display service status
echo "Service started, current status:"
sudo systemctl status "$SERVICE_NAME" --no-pager

echo -e "Setup complete, service will auto-start on boot!"