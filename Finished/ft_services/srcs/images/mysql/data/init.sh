while [ -f /var/lib/mysql/isUp ];
do
    echo "#"
    sleep 1
done

mysql_install_db --user=root --basedir=/usr --datadir=/var/lib/mysql


mysqld_safe --user=root &

sleep 2

mysql < /create_tables.sql
mysql < /init_remote.sql
mysql < /init_wp.sql
mysql wordpress < /init_wp_data.sql

tail -f /dev/null
