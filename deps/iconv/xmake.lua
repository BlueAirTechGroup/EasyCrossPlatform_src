add_defines("BUILDING_LIBICONV","BUILDING_LIBCHARSET")
add_includedirs("include")
add_files("source/*.c")
target("iconv_s")
	set_kind("static")
	add_defines("USING_STATIC_LIBICONV")

target("iconv")
	set_kind("shared")