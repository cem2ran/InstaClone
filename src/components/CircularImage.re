open ReactNative;
open Style;
include Image;

let makeProps = (~size: float) =>
  Styled.image(style =>
    style(~width=size->dp, ~height=size->dp, ~borderRadius=size /. 2., ())
  );
