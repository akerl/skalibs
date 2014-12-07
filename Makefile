BUILD_DIR = /tmp/skalibs-build

.PHONY : default build_container manual container build push local

default: container

manual:
	./meta/launch /bin/bash || true

container:
	./meta/launch

build:
	rm -rf $(BUILD_DIR)
	cp -R upstream $(BUILD_DIR)
	patch -d $(BUILD_DIR) -p1 < patch
	make -C $(BUILD_DIR) install
	tar -czv -C /tmp/skalibs-release -f skalibs.tar.gz .

push:
	git commit -am "$$(cat upstream/package/version)" || true
	ssh -oStrictHostKeyChecking=no git@github.com &>/dev/null || true
	git tag -f "$$(cat upstream/package/version)"
	git push --tags origin master
	targit -a .github -c -f akerl/skalib $$(cat upstream/package/version) skalibs.tar.gz

local: build push

