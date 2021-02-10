#!/bin/bash

function del_docker() {
	echo -ne "\t$1...               \r"
	docker rmi $2 services_$1 > /dev/null
}

function del_dep() {
	echo -ne "\t$1...               \r"
	kubectl delete -f ./deployments/dep-$1.yaml > /dev/null
}

function del_serv() {
	echo -ne "\t$1...               \r"
	kubectl delete -f ./services/service-$1.yaml > /dev/null
}

function del_vol() {
	echo -ne "\t$1...               \r"
	kubectl delete -f ./volumes/claims/claim-$1.yaml > /dev/null &
	kubectl delete -f ./volumes/volume-$1.yaml  > /dev/null &
}

function del_addon() {
	echo -ne "\t$1...               \r"
	kubectl delete -f ./addons/addon-$1.yaml > /dev/null
}

function mass_del() {
	i=0
	for var in $@; do
		if [[ $i -ge 1 ]]; then
			$1 $var
		fi
		((i=i+1))
	done
}
