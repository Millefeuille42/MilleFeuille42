#!/bin/bash
if [[ ! $(command -v minikube) ]]
then 
	echo "Installing Minikube ..."
	curl -Lo minikube https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64 && chmod +x minikube
	if [[ $? != 0 ]]
	then
		echo "Error: cannot download minikube ..."
		exit 1
	fi
	PATH=$PATH:/usr/local/bin/
	sudo mkdir -p /usr/local/bin/
	sudo install minikube /usr/local/bin/
fi
