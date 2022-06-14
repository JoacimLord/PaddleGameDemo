include "Dependencies.lua"

workspace "LFW_PaddleDemo"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	--solution_items
	--{
	--	".editorconfig"
	--}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Luna/Vendor/GLFW"
	include "Luna/Vendor/Glad"
	include "Luna/Vendor/imgui"
group ""

include "Luna"
include "Sandbox"