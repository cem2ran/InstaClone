open ReactNative;
open Styles;
include View;

let style = centered =>
  ViewStyle({
    backgroundColor: "#fff",
    flex: 1.,
    justifyContent: centered ? `center : `flexStart,
    alignItems: centered ? `center : `flexStart,
  });

let makeProps = (~centered=false, ~style as additionalStyle=Style.style()) =>
  makeProps(~style=list([style(centered), additionalStyle]));