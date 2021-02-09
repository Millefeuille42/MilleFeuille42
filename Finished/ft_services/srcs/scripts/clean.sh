#!/bin/bash

source ./scripts/libs/clean.lib.sh

echo "Setting Up Environment..."
eval $(minikube docker-env)

cd ./kubernetes

echo "Deleting Addons:"
mass_del del_addon metallb
echo -ne "\tDone!                 \n"

echo "Cleaning Services:"
mass_del del_serv mysql phpmyadmin wordpress nginx ftps influxdb grafana
echo -ne "\tDone!                \n"

echo "Cleaning Deployments:"
mass_del del_dep mysql phpmyadmin wordpress nginx ftps influxdb grafana
echo -ne "\tDone!                 \n"

echo "Cleaning Volumes:"
mass_del del_vol mysql influxdb
echo -ne "\tDone!               \n"

echo -ne "Waiting for pods to terminate...\r"
sleep 5
cd ../images
echo "Cleaning images:                           "
mass_del del_docker mysql phpmyadmin wordpress nginx ftps influxdb grafana
echo -ne "\tDone!               \n"
