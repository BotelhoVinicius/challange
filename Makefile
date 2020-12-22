SHELL=/bin/bash

IMAGE := challenge:latest

WORK_DIR := $(PWD)
WORK_SCRIPT_DIR := scripts
MAKEFILE_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

HOST_SHARED_DIR := $(WORK_DIR)
GUEST_WORK_DIR := $(shell echo "$(HOME)/$$(basename $(WORK_DIR))")
HOST_SHARED_VOLUME := shared
GUEST_SHARED_VOLUME := /mnt/shared

DOCKER_NETWORK := challenge_network

USER := $(shell id -u):$(shell id -g)

DOCKER_RUN_COMMON:= docker run --rm \
  --name challenge-$(shell date +%s) \
  --volume $(HOST_SHARED_VOLUME):$(GUEST_SHARED_VOLUME) \
  --volume $(HOST_SHARED_DIR):$(GUEST_WORK_DIR) \
	--network $(DOCKER_NETWORK) \
  --workdir $(GUEST_WORK_DIR)

DOCKER_RUN:= $(DOCKER_RUN_COMMON) \
	--user $(USER) \
	$(IMAGE)

DOCKER_BUILD = docker image build --tag $(IMAGE) .

# make help options
OPT_BUILD           :=build                     build source code
OPT_BUILD_IMG       :=build-image               build docker image
OPT_CLEAN           :=clean                     build clean
OPT_HELP            :=help                      print this help message and exit
OPT_SHELL           :=shell                     run container using iterative shell
OPT_SHELL_SERVER    :=shell-server              run server container using iterative shell
OPT_TEST            :=test                      run unit tests

.DEFAULT_GOAL := help

build:
	@echo 'Starting application build proceeding'
	@$(DOCKER_RUN) \
		"scripts/build"

clean:
	@$(DOCKER_RUN) \
		"scripts/clean"

help:
	@echo 'Makefile: utility which simplifies docker usage'
	@echo
	@echo 'Options:'
	@echo '  $(OPT_BUILD)'
	@echo '  $(OPT_BUILD_IMG)'
	@echo '  $(OPT_CLEAN)'
	@echo '  $(OPT_HELP)'
	@echo '  $(OPT_SHELL)'
	@echo '  $(OPT_SHELL_SERVER)'
	@echo '  $(OPT_TEST)'

shell:
	@echo 'Starting container with iterative shell'
	@$(DOCKER_RUN_COMMON) \
		-it \
		challenge:latest

shell-server:
	@echo 'Starting server container with iterative shell'
	@$(DOCKER_RUN_COMMON) \
		--network-alias server \
		-it \
		challenge:latest

test: build
	@$(DOCKER_RUN) \
		"scripts/test"

build-image:
	@$(DOCKER_BUILD)
