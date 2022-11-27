# Makefile for creating vcf-validator Docker image
#

# 1st item is default, so 'make' with no arguments shows help
## help: show this help message
help:
	@echo "Usage: \n"
	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' | sed -e 's/^/ /' | sort

# define docker to run using BUILDKIT features
DOCKER = DOCKER_BUILDKIT=1 docker

# Platforms defaults to amd64 and arm64, but one can override at runtime (e.g., PLATFORMS=linux/amd64 make xxx)
PLATFORMS ?= linux/amd64,linux/arm64

# Set buildx builder
BUILDER ?= builder-local

# vcf-validator version (assumed to be a git tag)
VCF_VALIDATOR_VERSION ?= 0.9.4

# TAG
TAG = $(REPO_NAME)/vcf-validator:$(VCF_VALIDATOR_VERSION)

require_repo_name:
ifndef REPO_NAME
	$(error REPO_NAME not set)
endif

## build: build using local architecture
build: require_repo_name
	@echo '=> Build $(TAG)...'
	$(DOCKER) build --file Dockerfile \
		--build-arg VCF_VALIDATOR_VERSION=$(VCF_VALIDATOR_VERSION) \
		--pull --tag $(TAG) .

# common setup for buildx tasks
buildx-setup: require_repo_name
	@echo "Current buildx builders:"
	$(DOCKER) buildx ls
	@if ! $(DOCKER) buildx inspect --builder $(BUILDER) > /dev/null 2>&1; then \
  		echo "Creating new builder '$(BUILDER)'"; \
  		$(DOCKER) buildx create --name $(BUILDER); \
	else \
		echo "Using existing builder $(BUILDER)"; \
	fi

## buildx-publish: build and publish the multi-architecture image (amd64|arm64)
buildx-publish: require_repo_name buildx-setup
	@echo '=> Build and publish multi-arch image $(TAG)...'
	$(DOCKER) buildx build --file Dockerfile \
		--platform $(PLATFORMS) \
		--builder $(BUILDER) \
		--build-arg VCF_VALIDATOR_VERSION=$(VCF_VALIDATOR_VERSION) \
		--progress plain \
		--pull --push --tag $(TAG) .
