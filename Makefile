corepackages=build-essential CMake lib32z1 lib32ncurses5 lib32bz2-1.0

all: packages arm-tools ## Make it all!

packages: ## get dependencies from debian servers
	sudo apt-get install aptitude
	for i in $(corepackages) ; do \
		echo installing $$i ; \
		sudo aptitude install $$i ; \
	done

arm-tools: ## install arm toolchain in /usr/local
	echo export PATH="/usr/local/arm_linux_4.2/bin:$$PATH" >> ~/.bashrc
	source ~/.bashrc
	echo linking arm_linux_4.2 into /usr/local/
	ln -s `pwd`/arm_linux_4.2/ /usr/local/

.PHONY: help
help:
	@perl -nle'print $& if m{^[a-zA-Z_-]+:.*?## .*$$}' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'


# unzip arm_linux_4.2 -d /usr/local/
