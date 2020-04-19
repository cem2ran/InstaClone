open ReactNative;

let text = (x, ~style=Style.style(), ~value: option(string)=?, ~children=?) => {
  let children =
    value
    |> (
      fun
      | Some(text) => Some(text->React.string)
      | None => children
    );
  Text.makeProps(
    ~children?,
    ~style=Style.list([x(Style.textStyle), style]),
  );
};

let view = (x, ~style=Style.style()) =>
  View.makeProps(~style=Style.list([x(Style.viewStyle), style]));

let image = (x, ~style=Style.style()) =>
  Image.makeProps(~style=Style.list([x(Style.viewStyle), style]));

module type TextT = {
  type element = ReactNative.NativeElement.element;
  type ref = React.Ref.t(Js.nullable(element));
  let findNodeHandle: element => ReactNative.NativeTypes.nodeHandle;
  let setNativeProps: (element, Js.t('a)) => unit;
  let focus: element => unit;
  let blur: element => unit;
  let measure:
    (element, ReactNative.NativeTypes.measureResult => unit) => unit;
  let measureInWindow:
    (element, ReactNative.NativeTypes.measureInWindowResult => unit) => unit;
  let measureLayout:
    (
      element,
      ~relativeToNativeNode: ReactNative.NativeTypes.nodeHandle,
      ~onSuccess: ReactNative.NativeTypes.measureResult => unit,
      ~onFail: ReactNative.NativeTypes.measureError => unit
    ) =>
    unit;
  let makeProps:
    (
      ~ref: ref=?,
      ~accessible: bool=?,
      ~accessibilityHint: string=?,
      ~accessibilityLabel: string=?,
      ~allowFontScaling: bool=?,
      ~ellipsizeMode: [ | `clip | `head | `middle | `tail]=?,
      ~numberOfLines: int=?,
      ~onLayout: ReactNative.Event.layoutEvent => unit=?,
      ~onLongPress: unit => unit=?,
      ~onPress: unit => unit=?,
      ~pressRetentionOffset: ReactNative.View.edgeInsets=?,
      ~selectable: bool=?,
      ~style: ReactNative.Style.t=?,
      ~testID: string=?,
      ~selectionColor: string=?,
      ~textBreakStrategy: [ | `balanced | `highQuality | `simple]=?,
      ~adjustsFontSizeToFit: bool=?,
      ~minimumFontScale: float=?,
      ~suppressHighlighting: bool=?,
      ~value: string=?,
      ~children: React.element=?,
      ~key: string=?,
      unit
    ) =>
    {
      .
      "accessibilityHint": option(string),
      "accessibilityLabel": option(string),
      "accessible": option(bool),
      "adjustsFontSizeToFit": option(bool),
      "allowFontScaling": option(bool),
      "children": option(React.element),
      "ellipsizeMode": option([ | `clip | `head | `middle | `tail]),
      "minimumFontScale": option(float),
      "numberOfLines": option(int),
      "onLayout": option(ReactNative.Event.layoutEvent => unit),
      "onLongPress": option(unit => unit),
      "onPress": option(unit => unit),
      "pressRetentionOffset": option(ReactNative.View.edgeInsets),
      "ref": option(ref),
      "selectable": option(bool),
      "selectionColor": option(string),
      "style": option(ReactNative.Style.t),
      "suppressHighlighting": option(bool),
      "testID": option(string),
      "textBreakStrategy": option([ | `balanced | `highQuality | `simple]),
      "value": option(string),
    };

  let make:
    React.componentLike(
      {
        .
        "accessibilityHint": option(string),
        "accessibilityLabel": option(string),
        "accessible": option(bool),
        "adjustsFontSizeToFit": option(bool),
        "allowFontScaling": option(bool),
        "children": option(React.element),
        "ellipsizeMode": option([ | `clip | `head | `middle | `tail]),
        "minimumFontScale": option(float),
        "numberOfLines": option(int),
        "onLayout": option(ReactNative.Event.layoutEvent => unit),
        "onLongPress": option(unit => unit),
        "onPress": option(unit => unit),
        "pressRetentionOffset": option(ReactNative.View.edgeInsets),
        "ref": option(ref),
        "selectable": option(bool),
        "selectionColor": option(string),
        "style": option(ReactNative.Style.t),
        "suppressHighlighting": option(bool),
        "testID": option(string),
        "textBreakStrategy": option([ | `balanced | `highQuality | `simple]),
        "value": option(string),
      },
      React.element,
    );
};