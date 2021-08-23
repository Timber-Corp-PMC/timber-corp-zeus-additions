class RscObject;
class RscText;
class RscFrame;
class RscLine;
class RscProgress;
class RscPicture;
class RscPictureKeepAspect;
class RscVideo;
class RscHTML;
class RscButton;
class RscShortcutButton;
class RscEdit;
class RscCombo;
class RscListBox;
class RscListNBox;
class RscXListBox;
class RscTree;
class RscSlider;
class RscXSliderH;
class RscActiveText;
class RscActivePicture;
class RscActivePictureKeepAspect;
class RscStructuredText;
class RscToolbox;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscControlsGroupNoVScrollbars;
class RscButtonTextOnly;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscButtonMenuSteam;
class RscMapControl;
class RscMapControlEmpty;
class RscCheckBox;
class RscBackground;
class RscTitle;
class RscTitleText;

//ZEN UI classes
class zen_common_RscEdit;
class zen_common_RscLabel;

class zen_common_RscDisplay {
    class controls {
        class Title;
        class Background;
        class Content;
        class ButtonOK;
        class ButtonCancel;
    }
};

class GVAR(RscDisplay): zen_common_RscDisplay {
    class controls: controls {
        class Title: Title {};
        class Background: Background {};
        class Content: Content {};
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
};
