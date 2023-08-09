#pragma once

#include <WDK/String.hpp>

#include <vector>

#include <windows.h>

namespace WDK
{
	class Rectangle;

	class Window
	{
	public:

		/// <summary>
		/// Window events for callbacks
		/// </summary>
		enum Event
		{
			Null = WM_NULL,
			Create = WM_CREATE,
			Destroy = WM_DESTROY,
			Move = WM_MOVE,
			Size = WM_SIZE,

			Activate = WM_ACTIVATE,
			SetFocus = WM_SETFOCUS,
			KillFocus = WM_KILLFOCUS,

			Enable = WM_ENABLE,
			SetRedraw = WM_SETREDRAW,
			SetText = WM_SETTEXT,
			GetText = WM_GETTEXT,
			GetTextLength = WM_GETTEXTLENGTH,
			Paint = WM_PAINT,
			Close = WM_CLOSE,

			QueryEndSession = WM_QUERYENDSESSION,
			QueryOpen = WM_QUERYOPEN,

			EndSession = WM_ENDSESSION,
			Quit = WM_QUIT,
			EraseBackground = WM_ERASEBKGND,
			SysColorChange = WM_SYSCOLORCHANGE,
			ShowWindow = WM_SHOWWINDOW,
			WinIniChange = WM_WININICHANGE,
			SettingChange = WM_SETTINGCHANGE,

			DevModeChange = WM_DEVMODECHANGE,
			ActivateApp = WM_ACTIVATEAPP,
			FontChange = WM_FONTCHANGE,
			TimeChange = WM_TIMECHANGE,
			CancelMode = WM_CANCELMODE,
			SetCursor = WM_SETCURSOR,
			MouseActivate = WM_MOUSEACTIVATE,
			ChildActivate = WM_CHILDACTIVATE,
			QueueSync = WM_QUEUESYNC,

			GetMinMaxInfo = WM_GETMINMAXINFO,

			PaintIcon = WM_PAINTICON,
			IconEraseBackground = WM_ICONERASEBKGND,
			NextDialogControl = WM_NEXTDLGCTL,
			SpoolerStatus = WM_SPOOLERSTATUS,
			DrawItem = WM_DRAWITEM,
			MeasureItem = WM_MEASUREITEM,
			DeleteItem = WM_DELETEITEM,
			VKeyToItem = WM_VKEYTOITEM,
			CharToItem = WM_CHARTOITEM,
			SetFont = WM_SETFONT,
			GetFont = WM_GETFONT,
			SetHotkey = WM_SETHOTKEY,
			GetHotkey = WM_GETHOTKEY,
			QueryDragIcon = WM_QUERYDRAGICON,
			CompareItem = WM_COMPAREITEM,

			GetObject = WM_GETOBJECT,
			Compacting = WM_COMPACTING,
			CommNotify = WM_COMMNOTIFY,
			WindowPosChanging = WM_WINDOWPOSCHANGING,
			WindowPosChanged = WM_WINDOWPOSCHANGED,
			Power = WM_POWER,

			CopyData = WM_COPYDATA,
			CancelJournal = WM_CANCELJOURNAL,
			Notify = WM_NOTIFY,
			InputLangChange = WM_INPUTLANGCHANGE,
			TCard = WM_TCARD,
			Help = WM_HELP,
			UserChanged = WM_USERCHANGED,
			NotifyFormat = WM_NOTIFYFORMAT,
			ContextMenu = WM_CONTEXTMENU,
			StyleChanging = WM_STYLECHANGING,
			StyleChanged = WM_STYLECHANGED,
			DisplayChange = WM_DISPLAYCHANGE,
			GetIcon = WM_GETICON,
			SetIcon = WM_SETICON,
			NcCreate = WM_NCCREATE,
			NcDestroy = WM_NCDESTROY,
			NcCalcSize = WM_NCCALCSIZE,
			NcHitTest = WM_NCHITTEST,
			NcPaint = WM_NCPAINT,
			NcActivate = WM_NCACTIVATE,
			GetDlgCode = WM_GETDLGCODE,
			SyncPaint = WM_SYNCPAINT,
			NcMouseMove = WM_NCMOUSEMOVE,
			NcLButtonDown = WM_NCLBUTTONDOWN,
			NcLButtonUp = WM_NCLBUTTONUP,
			NcLButtonDblClk = WM_NCLBUTTONDBLCLK,
			NcRButtonDown = WM_NCRBUTTONDOWN,
			NcRButtonUp = WM_NCRBUTTONUP,
			NcRButtonDblClk = WM_NCRBUTTONDBLCLK,
			NcMButtonDown = WM_NCMBUTTONDOWN,
			NcMButtonUp = WM_NCMBUTTONUP,
			NcMButtonDblClk = WM_NCMBUTTONDBLCLK,

			KeyFirst = WM_KEYFIRST,
			KeyDown = WM_KEYDOWN,
			KeyUp = WM_KEYUP,
			Char = WM_CHAR,
			DeadChar = WM_DEADCHAR,
			SysKeyDown = WM_SYSKEYDOWN,
			SysKeyUp = WM_SYSKEYUP,
			SysChar = WM_SYSCHAR,
			SysDeadChar = WM_SYSDEADCHAR,
			KeyLast = WM_KEYLAST,

			ImeStartComposition = WM_IME_STARTCOMPOSITION,
			ImeEndComposition = WM_IME_ENDCOMPOSITION,
			ImeComposition = WM_IME_COMPOSITION,
			ImeKeyLast = WM_IME_KEYLAST,

			InitDialog = WM_INITDIALOG,
			Command = WM_COMMAND,
			SysCommand = WM_SYSCOMMAND,
			Timer = WM_TIMER,
			HScroll = WM_HSCROLL,
			VScroll = WM_VSCROLL,
			InitMenu = WM_INITMENU,
			InitMenuPopup = WM_INITMENUPOPUP,
			Gesture = WM_GESTURE,
			GestureNotify = WM_GESTURENOTIFY,
			MenuSelect = WM_MENUSELECT,
			MenuChar = WM_MENUCHAR,
			EnterIdle = WM_ENTERIDLE,
			MenuRButtonUp = WM_MENURBUTTONUP,
			MenuDrag = WM_MENUDRAG,
			MenuGetObject = WM_MENUGETOBJECT,
			UninitMenuPopup = WM_UNINITMENUPOPUP,
			MenuCommand = WM_MENUCOMMAND,

			ChangeUIState = WM_CHANGEUISTATE,
			UpdateUIState = WM_UPDATEUISTATE,
			QueryUIState = WM_QUERYUISTATE,

			CtlColorMsgBox = WM_CTLCOLORMSGBOX,
			CtlColorEdit = WM_CTLCOLOREDIT,
			CtlColorListBox = WM_CTLCOLORLISTBOX,
			CtlColorBtn = WM_CTLCOLORBTN,
			CtlColorDlg = WM_CTLCOLORDLG,
			CtlColorScrollBar = WM_CTLCOLORSCROLLBAR,
			CtlColorStatic = WM_CTLCOLORSTATIC,
			MouseFirst = WM_MOUSEFIRST,
			MouseMove = WM_MOUSEMOVE,
			LButtonDown = WM_LBUTTONDOWN,
			LButtonUp = WM_LBUTTONUP,
			LButtonDblClk = WM_LBUTTONDBLCLK,
			RButtonDown = WM_RBUTTONDOWN,
			RButtonUp = WM_RBUTTONUP,
			RButtonDblClk = WM_RBUTTONDBLCLK,
			MButtonDown = WM_MBUTTONDOWN,
			MButtonUp = WM_MBUTTONUP,
			MButtonDblClk = WM_MBUTTONDBLCLK,
			MouseWheel = WM_MOUSEWHEEL,
			XButtonDown = WM_XBUTTONDOWN,
			XButtonUp = WM_XBUTTONUP,
			XButtonDblClk = WM_XBUTTONDBLCLK,
			MouseLast = WM_MOUSELAST,

			ParentNotify = WM_PARENTNOTIFY,
			EnterMenuLoop = WM_ENTERMENULOOP,
			ExitMenuLoop = WM_EXITMENULOOP,
			NextMenu = WM_NEXTMENU,
			Sizing = WM_SIZING,
			CaptureChanged = WM_CAPTURECHANGED,
			Moving = WM_MOVING,
			PowerBroadcast = WM_POWERBROADCAST,
			DeviceChange = WM_DEVICECHANGE,

			Mdicreate = WM_MDICREATE,
			Mdidestroy = WM_MDIDESTROY,
			Mdiactivate = WM_MDIACTIVATE,
			MdiRestore = WM_MDIRESTORE,
			MdiNext = WM_MDINEXT,
			MdiMaximize = WM_MDIMAXIMIZE,
			MdiTile = WM_MDITILE,
			MdiCascade = WM_MDICASCADE,
			MdiIconArrange = WM_MDIICONARRANGE,
			MdiGetActive = WM_MDIGETACTIVE,
			MdiSetMenu = WM_MDISETMENU,

			EnterSizeMove = WM_ENTERSIZEMOVE,
			ExitSizeMove = WM_EXITSIZEMOVE,
			DropFiles = WM_DROPFILES,
			MdiRefreshMenu = WM_MDIREFRESHMENU,

			PointerDeviceChange = WM_POINTERDEVICECHANGE,
			PointerDeviceInRange = WM_POINTERDEVICEINRANGE,
			PointerDeviceOutOfRange = WM_POINTERDEVICEOUTOFRANGE,
			Touch = WM_TOUCH,
			NcPointerUpdate = WM_NCPOINTERUPDATE,
			NcPointerDown = WM_NCPOINTERDOWN,
			NcPointerUp = WM_NCPOINTERUP,
			PointerUpdate = WM_POINTERUPDATE,
			PointerDown = WM_POINTERDOWN,
			PointerUp = WM_POINTERUP,
			PointerEnter = WM_POINTERENTER,
			PointerLeave = WM_POINTERLEAVE,
			PointerActivate = WM_POINTERACTIVATE,
			PointerCaptureChanged = WM_POINTERCAPTURECHANGED,
			TouchHittesting = WM_TOUCHHITTESTING,
			PointerWheel = WM_POINTERWHEEL,
			PointerHWheel = WM_POINTERHWHEEL,
			Dpichanged = WM_DPICHANGED,
			DpichangedBeforeParent = WM_DPICHANGED_BEFOREPARENT,
			DpichangedAfterParent = WM_DPICHANGED_AFTERPARENT,
		};

		/// <summary>
		/// Values for Event::Activate
		/// </summary>
		enum ActivateState
		{
			Inactive = WA_INACTIVE,
			Active = WA_ACTIVE,
			ClickActive = WA_CLICKACTIVE
		};

		/// <summary>
		/// Values for window Style
		/// </summary>
		enum Style
		{
			Border = WS_BORDER,
			Caption = WS_CAPTION,
			Child = WS_CHILD,
			ChildWindow = WS_CHILDWINDOW,
			ClipChildren = WS_CLIPCHILDREN,
			ClipSiblings = WS_CLIPSIBLINGS,
			Disabled = WS_DISABLED,
			DialogFrame = WS_DLGFRAME,
			Group = WS_GROUP,
			HorizontalScroll= WS_HSCROLL,
			Iconic = WS_ICONIC,
			Maximized = WS_MAXIMIZE,
			MaximizeBox = WS_MAXIMIZEBOX,
			Minimized = WS_MINIMIZE,
			MinimizeBox = WS_MINIMIZEBOX,
			Overlapped = WS_OVERLAPPED,
			OverlappedWindow = WS_OVERLAPPEDWINDOW,
			Popup = WS_POPUP,
			PopupWindow = WS_POPUPWINDOW,
			SizeBox = WS_SIZEBOX,
			SysMenu = WS_SYSMENU,
			TabStop = WS_TABSTOP,
			ThickFrame = WS_THICKFRAME,
			Tiled = WS_TILED,
			TiledWindow = WS_TILEDWINDOW,
			Visible = WS_VISIBLE,
			VerticalScroll = WS_VSCROLL,
		};

		/// <summary>
		/// Default constructor
		/// </summary>
		Window();

		/// <summary>
		/// Initialize a window from a native handle.
		/// </summary>
		/// <param name="_handle">The native handle to initialize from.</param>
		Window(::HWND _handle);

		/// <summary>
		/// Init constructor
		/// </summary>
		/// <param name="_title">The title of the window</param>
		/// <param name="_clientArea">The client area of the window</param>
		/// <param name="_style">The style of the window</param>
		/// <param name="_parent">Parent window</param>
		Window(
			WDK::String _title, 
			WDK::Rectangle _clientArea, 
			const Style _style = Style::OverlappedWindow, 
			Window _parent = Window()
		);

		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~Window();

		/// <summary>
		/// Gets the native window handle
		/// </summary>
		/// <returns>The native window handle</returns>
		::HWND GetNativeHandle() const;

		/// <summary>
		/// Changes the parent window of the specified child window.
		/// </summary>
		/// <param name="_parent">The new parent window. If this parameter is empty, the desktop window becomes the new parent window.</param>
		/// <returns>If the function succeeds, the return value is a handle to the previous parent window.</returns>
		Window SetParent(Window _parent = Window());

		/// <summary>
		/// Changes the parent window of the specified child window.
		/// </summary>
		/// <param name="_parent">The added child window.</param>
		/// <returns>If the function succeeds, the return value is a handle to the previous child' parent window.</returns>
		Window AddChild(Window _child);

		//TODO Zo: get children
		std::vector<Window> GetChildren() const;


		/// <summary>
		/// Gets the window style value. This is mainly for internal use.
		/// </summary>
		::DWORD GetNativeStyle() const; //TODO Zo: replace by enum

		/// <summary>
		/// Gets the window style value. This is mainly for internal use.
		/// </summary>
		::DWORD GetNativeExStyle() const; //TODO Zo: replace by enum
		
		/// <summary>
		/// Checks if the window is minimized.
		/// </summary>
		/// <returns>true if this is minimized, false otherwise</returns>
		bool IsMinimized() const;
		
		/// <summary>
		/// Checks if the window is maximized.
		/// </summary>
		/// <returns>true if this is maximized, false otherwise</returns>
		bool IsMaximized() const;

		/// <summary>
		/// Checks if the window is visible.
		/// </summary>
		/// <returns>true if this is visible, false otherwise</returns>
		bool IsVisible() const;

		/// <summary>
		/// Checks if the window is open
		/// </summary>
		/// <returns>true if the window is open, false otherwise</returns>
		bool IsOpen();

		/// <summary>
		/// Checks if the window is a Menu window. This is for internal use.
		/// </summary>
		/// <returns>true if this is a window menu, false otherwise</returns>
		virtual bool IsMenu() const;

		/// <summary>
		/// Shows the window
		/// </summary>
		void Open();

		/// <summary>
		/// Updates and returns whether the window is open
		/// </summary>
		/// <returns>Whether the window is open</returns>
		void Update();

	private:
		::HWND m_handle;
		::ATOM m_class;

		/// <summary>
		/// The native window procedure. This method is in charge of dispatching events to callbacks.
		/// </summary>
		/// <param name="_hWnd">The native window handle. This is set by the Operating System.</param>
		/// <param name="_uMsg">The message ID. This is set by the Operating System.</param>
		/// <param name="_wParam">An additional parameter. This is set by the Operating System based on _uMsg value.</param>
		/// <param name="_lParam">An additional parameter. This is set by the Operating System based on _uMsg value.</param>
		/// <returns>0 if the event have been handled. Non-zero value otherwise.</returns>
		static ::LRESULT CALLBACK WndProc(
			::HWND _hWnd,
			::UINT _uMsg,
			::WPARAM _wParam,
			::LPARAM _lParam
		);
	};
}