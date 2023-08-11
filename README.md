# Windows Development Kit

WDK is a C++ Wrapper for the Windows API. <br>
Although it provides helper functions, it is designed to be a simple OOP wrapper for the Windows API and is not intended to be a full-fledged framework.

# Usage

Include the WDK.h header file in your project, and link against the WDK.lib library. <br>
Alternatively, you could include the WDK project in your solution and add it as a reference for your project.

Either way, you will need to add the include directory to your project's additionnal include directories.

[ADD DETAILED INFOS]

# Requirements

- [Microsoft Visual Studio](https://visualstudio.microsoft.com/fr/) 2019 or Higher. Alternatively, you can use [Jetbrains Rider](https://www.jetbrains.com/fr-fr/rider/).

# Example

```cpp
#include <WDK/WDK.hpp>

int main(int _argc, char* _argv[])
{
	WDK::Rectangle clientArea = WDK::Rectangle::FromDimension(CW_USEDEFAULT, CW_USEDEFAULT, 800, 600); //client area
	WDK::WindowClass nclass(TEXT("WDKClass")); //creates a wndclassex with minimum default data

	nclass.Register(); //you should check for error here but I keep the example straight to the point 

	WDK::Window wnd(nclass, TEXT("WDK"), clientArea);

	wnd.Open();

	WDK::Message msg;
	while (msg.Get(wnd))
	{
		msg.TranslateAndDispatch(); //do both translate and dispatch at the same time (methods exists separately in Mesasge class)
	}

	wnd.Destroy();
	nclass.UnregisterSecure(); //checks if nobody uses the class before deleting

	return 0;
}

```

# License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details
