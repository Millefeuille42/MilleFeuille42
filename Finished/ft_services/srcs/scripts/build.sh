#!/bin/bash

source ./scripts/libs/build.lib.sh

echo "Setting Up Environment..."
eval $(minikube docker-env)

echo "Setting Up Addons:"
cd ./kubernetes/
mass_set kub_addon metallb
echo -ne "\tDone!         \n"

echo "Building Images:"
cd ../images/
mass_set doc_build mysql phpmyadmin wordpress nginx influxdb grafana
doc_build ftps "--build-arg KIP=$(minikube ip)"
echo -ne "\tDone!         \n"

echo "Creating Volumes:"
cd ../kubernetes/
mass_set kub_vol mysql influxdb
echo -ne "\tDone!                \n"

echo "Setting Up Deployments:"
mass_set kub_dep mysql phpmyadmin wordpress nginx ftps influxdb grafana
echo -ne "\tDone!            \n"

echo "Setting Up Services:"
mass_set kub_serv mysql phpmyadmin wordpress nginx ftps influxdb grafana
echo -ne "\tDone!         \n"
