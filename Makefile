PACKAGE = skalibs
BUILD_DIR = /tmp/$(PACKAGE)-build
RELEASE_DIR = /tmp/$(PACKAGE)-release
RELEASE_FILE = $(PACKAGE).tar.gz

PACKAGE_VERSION = $$(cat upstream/package/version)
PATCH_VERSION = $$(cat version)
VERSION = $(PACKAGE_VERSION)-$(PATCH_VERSION)

.PHONY : default manual container version build push local

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
	tar -czv -C $(RELEASE_DIR) -f $(RELEASE_FILE) .

version:
	@echo $$(($(PATCH_VERSION) + 1)) > version

push: version
	git commit -am "$(VERSION)"
	ssh -oStrictHostKeyChecking=no git@github.com &>/dev/null || true
	git tag -f "$(VERSION)"
	git push --tags origin master
	targit -a .github -c -f akerl/skalibs $(VERSION) $(RELEASE_FILE)

local: build push

