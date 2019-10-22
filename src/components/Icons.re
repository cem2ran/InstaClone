module EvilIcons = {
  [@bs.module "@expo/vector-icons"] [@react.component]
  external make: (~name: string, ~size: int, ~color: string) => React.element =
    "EvilIcons";
};

module FontAwesome = {
  [@bs.module "@expo/vector-icons"] [@react.component]
  external make: (~name: string, ~size: int, ~color: string) => React.element =
    "FontAwesome";
};

module Feather = {
  [@bs.module "@expo/vector-icons"] [@react.component]
  external make: (~name: string, ~size: int, ~color: string) => React.element =
    "Feather";
};

module Ionicons = {
  [@bs.module "@expo/vector-icons"] [@react.component]
  external make: (~name: string, ~size: int, ~color: string) => React.element =
    "Ionicons";
};
