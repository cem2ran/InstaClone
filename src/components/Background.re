open ReactNative;
open Style;
include View;

let makeProps = (~centered=false, ~style as additionalStyle=Style.style()) =>
  makeProps(
    ~style=
      list([
        style(
          ~backgroundColor="#fff",
          ~flex=1.,
          ~justifyContent=centered ? `center : `flexStart,
          ~alignItems=centered ? `center : `flexStart,
          (),
        ),
        additionalStyle,
      ]),
  );