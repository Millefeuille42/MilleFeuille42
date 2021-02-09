influxd &

sleep 8
influx < init.inf

telegraf & tail -f /dev/null
