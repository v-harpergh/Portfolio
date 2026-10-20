module;

#include <windows.h>

#include <string>

export module resources.windows;

export namespace windows {

void infoBox(std::string_view title, std::string_view message) {
	MessageBox(nullptr, message.data(), title.data(), MB_ICONINFORMATION | MB_OK);
}

}