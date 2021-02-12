#!/bin/bash

function doc_build() {
	echo -ne "\t$1...               \r"
	docker build $2 --quiet -t services_$1 ./$1 > /dev/null
}

function kub_dep() {
	echo -ne "\t$1...               \r"
	kubectl apply -f ./deployments/dep-$1.yaml > /dev/null
}

function kub_serv() {
	echo -ne "\t$1...               \r"
	kubectl apply -f ./services/service-$1.yaml > /dev/null
}

function kub_vol() {
	echo -ne "\t$1...               \r"
	kubectl apply -f ./volumes/volume-$1.yaml  > /dev/null
	kubectl apply -f ./volumes/claims/claim-$1.yaml > /dev/null
}

function kub_addon() {
	echo -ne "\t$1...               \r"
	kubectl apply -f ./addons/addon-$1.yaml > /dev/null
}

function mass_set() {
	i=0
	for var in $@; do
		if [[ $i -ge 1 ]]; then
			$1 $var
		fi
		((i=i+1))
	done
}
