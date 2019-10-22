open ReactNative;

open Style;
include View;

let makeProps =
  Styled.view(style =>
    style(~flexDirection=`row, ~display=`flex, ~alignItems=`center, ())
  );
