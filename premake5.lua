workspace "Skibbidy"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release" 
    }

    outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    project "Skibbidy"
        location "Skibbidy"
        kind "SharedLib"
        language "C++"

        targetdir ("bin/" .. outputDir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
        includedirs
        {
            "%{prj.name}/vendor/spdlog/include"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "10.0.22621.0"

            defines
            {
                "SKD_PLATFORM_WINDOWS",
                "SKD_BUILD_DLL"
            }

            postbuildcommands
            {
                ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/SandBox")
            }

        filter "configurations:Debug"
            defines "SKD_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "SKD_RELEASE"
            optimize "On"

    project "SandBox"
        location "SandBox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputDir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
        includedirs
        {
            "Skibbidy/vendor/spdlog/include",
            "Skibbidy/src"
        }
        links
        {
            "Skibbidy"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "10.0.22621.0"

            defines
            {
                "SKD_PLATFORM_WINDOWS"
            }

        filter "configurations:Debug"
            defines "SKD_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "SKD_RELEASE"
            optimize "On"