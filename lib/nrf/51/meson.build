# This file is part of the libopencm3 project.
#
# Copyright (C) 2023 1BitSquared <info@1bitsquared.com>
# Written by Rachel Mant <git@dragonmux.network>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

nrf51_cm3 = declare_dependency(
	sources: cm3_sources,
	include_directories: cm3_includes,
	dependencies: nrf51_vector_nvic,
)

# Sources specific to the 51 series
libnrf51_sources = files(
	'clock.c',
	'radio.c',
	'i2c.c',
)

libnrf51_common_args = [
	'-mcpu=cortex-m0',
	'-mthumb',
	'-msoft-float',
]

libnrf51_compile_args = [
	'-DNRF51',
]
libnrf51_compile_args += libnrf51_common_args

libnrf51_link_args = [
	f'-L@locm3_ld_script_path@',
]
libnrf51_link_args += libnrf51_common_args

# Build a static library for the target platform
libnrf51 = static_library(
	'opencm3_nrf51',
	[
		libnrf51_sources,
		libnrf_clock_sources,
		libnrf_gpio_sources,
		libnrf_i2c_sources,
		libnrf_ppi_sources,
		libnrf_radio_sources,
		libnrf_rtc_sources,
		libnrf_timer_sources,
		libnrf_uart_sources,
	],
	c_args: libnrf51_compile_args,
	include_directories: common_includes,
	implicit_include_directories: false,
	dependencies: [
		nrf51_cm3,
	],
	pic: false,
)

# Make the dependency available to use
opencm3_nrf51 = declare_dependency(
	compile_args: libnrf51_compile_args,
	include_directories: common_includes,
	dependencies: nrf51_cm3,
	link_with: libnrf51,
	link_args: libnrf51_link_args,
)

meson.override_dependency('opencm3_nrf51', opencm3_nrf51)
