project(
    'SomeGui',
    'cpp',
    version: '1.0.0',
    license: 'MIT'
)
project_description = '....'

# =========================
# Source and headers' files
# =========================

project_source_files = []
project_header_files = []

# ==============
# Subdirectories
# ==============

project_include_directory = [include_directories('include'), include_directories('.')]
subdir('include')
subdir('src')

# ============
# Dependencies
# ============

project_dependencies = [
    dependency('glfw3', required: true),
    dependency('wayland-client', required: true),
    dependency('skity', required: true),
    dependency('skity-codec', required: true)
]

# ================
# Project's settings
# ================

configure_file(
    output : 'config.hpp',
    configuration : {
        '_SOMEGUI_VERSION': '"' + meson.project_version() + '"',
        '_SOMEGUI_TARGET_ARCH_LINUX': get_option('_SOMEGUI_TARGET_ARCH_LINUX'),
        '_SOMEGUI_TARGET_ARCH_WINDOWS': get_option('_SOMEGUI_TARGET_ARCH_WINDOWS')
    }
)

# ================
# Project's target
# ================

testexe = library(
    'testexe',
    project_source_files,
    dependencies: project_dependencies,
    include_directories: project_include_directory,
    cpp_args: '-g'
)

# ======================
# Project's installation
# ======================
# Make this library usable from the system's package manager.

#install_headers(project_headers, subdir : meson.project_name())

pkg_mod = import('pkgconfig')
pkg_mod.generate(
    name: meson.project_name(),
    filebase: meson.project_name(),
    description: project_description,
    subdirs: meson.project_name(),
)

# =========================
# Make example applications
# =========================

subdir('examples')