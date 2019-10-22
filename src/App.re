open ReactNative;
open ReactNavigation;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "instructions": style(~textAlign=`center, ~color="#ffffff", ()),
    })
  );

[@genType]
[@react.component]
let app = () => {
  <Native.NavigationNativeContainer>
    <Config.Apollo.Provider> <Profile /> </Config.Apollo.Provider>
  </Native.NavigationNativeContainer>;
};