#!/bin/bash

(cd srcs/ ; ./scripts/install.sh)

if [[ $1 != "minikube" ]]; then
	echo "Starting Minikube..."
	minikube start --driver=docker > /dev/null
fi

echo "Cleaning Leftovers..."
(cd srcs/ ; ./scripts/clean.sh) 2> /dev/null

echo "Cleaning Minikube..."
minikube delete > /dev/null

(cd srcs/ ; ./scripts/build.sh)
