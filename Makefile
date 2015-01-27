PACKAGE = skalibs
ORG = amylum
BUILD_DIR = /tmp/$(PACKAGE)-build
RELEASE_DIR = /tmp/$(PACKAGE)-release
RELEASE_FILE = /tmp/$(PACKAGE).tar.gz

PACKAGE_VERSION = $$(awk -F= '/^version/ {print $$2}' upstream/package/info)
PATCH_VERSION = $$(cat version)
VERSION = $(PACKAGE_VERSION)-$(PATCH_VERSION)
CONF_FLAGS = --enable-static --enable-ipv6 --disable-slashpackage --enable-monotonic
PATH_FLAGS = --prefix=$(RELEASE_DIR) --dynlibdir=$(RELEASE_DIR)/usr/lib --libdir=$(RELEASE_DIR)/usr/lib/skalibs --sysdepdir=$(RELEASE_DIR)/usr/lib/skalibs/sysdeps --includedir=$(RELEASE_DIR)/usr/include

.PHONY : default manual container version build push local

default: upstream/Makefile container

upstream/Makefile:
	git submodule update --init

manual:
	./meta/launch /bin/bash || true

container:
	./meta/launch

build:
	rm -rf $(BUILD_DIR)
	cp -R upstream $(BUILD_DIR)
	cd $(BUILD_DIR) && CC="musl-gcc" ./configure $(CONF_FLAGS) $(PATH_FLAGS)
	make -C $(BUILD_DIR)
	make -C $(BUILD_DIR) install
	cd $(RELEASE_DIR) && tar -czvf $(RELEASE_FILE) *

version:
	@echo $$(($(PATCH_VERSION) + 1)) > version

push: version
	git commit -am "$(VERSION)"
	ssh -oStrictHostKeyChecking=no git@github.com &>/dev/null || true
	git tag -f "$(VERSION)"
	git push --tags origin master
	targit -a .github -c -f $(ORG)/$(PACKAGE) $(VERSION) $(RELEASE_FILE)

local: build push

