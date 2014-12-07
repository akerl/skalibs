DIR=$(shell pwd)

.PHONY : default build_container manual container build push local

default: container

manual:
	./meta/launch /bin/bash || true

container:
	./meta/launch

build:
	rm -rf /tmp/skalibs-build
	cp -R upstream /tmp/skalibs-build
	patch upstream/src/sys/gen-EXPORT < patches/gen-EXPORT.patch
	touch conf-compile/flag-usert conf-compile/flag-usemon
	rm conf-compile/flag-slashpackage
	make -C upstream

push:
	git commit -am "$$(cat upstream/package/version)"
	ssh -oStrictHostKeyChecking=no git@github.com &>/dev/null || true
	git tag -f "$$(cat upstream/package/version)"
	git push --tags origin master
	targit -a .github -c -f dock0/initrd $$(cat upstream/package/version)

local: build push

