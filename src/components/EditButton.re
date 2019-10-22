open ReactNative;

let style =
  Style.(
    style(
      ~alignItems=`center,
      ~borderColor="#E6E6E6",
      ~borderRadius=4.,
      ~borderWidth=1.5,
      ~padding=5.->dp,
      (),
    )
  );

[@react.component]
let make = () =>
  <TouchableOpacity style onPress={_ => Js.log("Pressed Edit Profile")}>
    <Typography.Edit> "Edit Profile"->React.string </Typography.Edit>
  </TouchableOpacity>;
