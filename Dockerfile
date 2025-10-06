# Lightweight development environment for Assembly and C development
FROM debian:bookworm-slim

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install essential development tools
RUN apt-get update -y && apt-get install -y \
    # Core build tools
    build-essential \
    # RISC-V cross-compilation and emulation
    gcc-riscv64-unknown-elf \
    qemu-system-misc \
    gdb-multiarch \
    # Essential debugging tools
    gdb \
    binutils \
    # Lightweight Python
    python3-minimal \
    # Essential utilities only
    git \
    wget \
    nano \
    sudo \
    curl \
    # Hex dumping utility (xxd is part of vim-common)
    vim-common \
    # Clean up to reduce image size
    && rm -rf /var/lib/apt/lists/* \
    && apt-get clean

# Create a non-root user for development with proper permissions
RUN useradd -m -s /bin/bash -u 1000 dev && \
    echo "dev ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    mkdir -p /home/dev/.vscode-server && \
    chown -R dev:dev /home/dev

# Install gdb-dashboard for better debugging experience
RUN wget -O /home/dev/.gdbinit https://github.com/cyrus-and/gdb-dashboard/raw/master/.gdbinit && \
    chown dev:dev /home/dev/.gdbinit

RUN apt-get update && apt-get install -y python3-pygments

# Set up working directory
WORKDIR /workspace

# Switch to non-root user
USER dev

# Set default shell
SHELL ["/bin/bash", "-c"]
