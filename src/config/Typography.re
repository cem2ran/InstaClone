open ReactNative;

module Edit = {
  include Text;

  let make = Text.make;

  let makeProps =
    Styled.text(style =>
      style(~fontSize=13., ~fontWeight=`_700, ~color="#333", ())
    );
};

module Description = {
  include Text;

  let makeProps =
    Styled.text(style =>
      style(~fontSize=13., ~fontWeight=`_500, ~color="#555", ())
    );
};

module Link = {
  include Text;

  let makeProps =
    Styled.text(style =>
      style(~fontSize=13., ~fontWeight=`_500, ~color="#365B87", ())
    );
};

module Name = {
  include Text;

  let makeProps =
    Styled.text(style =>
      style(~fontSize=14., ~fontWeight=`_700, ~color="#222", ())
    );
};

module T2 = {
  include Text;

  let makeProps =
    Styled.text(style => style(~fontSize=12., ~fontWeight=`_700, ()));
};

module T3 = {
  include Text;

  let makeProps =
    Styled.text(style =>
      style(~fontSize=11., ~fontWeight=`_400, ~color="#333", ())
    );
};

module T4 = {
  include Text;

  let makeProps =
    Styled.text(style =>
      style(~fontSize=12., ~fontWeight=`_400, ~color="#333", ())
    );
};

module T4_Bold = {
  include Text;

  let makeProps =
    Styled.text(style =>
      style(~fontSize=12., ~fontWeight=`_700, ~color="#333", ())
    );
};