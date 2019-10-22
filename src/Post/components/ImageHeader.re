open ReactNative;
open Typography;

open PostData;

[@react.component]
let make = (~image as uri, ~location, ~username) => {
  Style.(
    <Horizontal
      style={Style.style(
        ~justifyContent=`spaceBetween,
        ~paddingHorizontal=7.->dp,
        ~paddingVertical=10.->dp,
        (),
      )}>
      <Horizontal>
        <TouchableWithoutFeedback
          onPress={_ => Js.log("Click Profile Image")}>
          <CircularImage
            size=32.
            source=Image.(Source.fromUriSource(uriSource(~uri, ())))
          />
        </TouchableWithoutFeedback>
        <View
          style={Style.style(
            ~paddingLeft=7.->dp,
            ~justifyContent=`center,
            (),
          )}>
          <T2 value=username />
          <T3
            value={
              switch (location) {
              | Some({city: Some(city), country: Some(country)}) => {j|$city, $country|j}
              | _ => ""
              }
            }
          />
        </View>
      </Horizontal>
      <MoreButton />
    </Horizontal>
  );
};
