open ReactNative;

let keyExtractor = (item, _index) => item##id;

let window = Dimensions.get(`window);

let width = window##width /. 3.;

let renderItem = (onPress, data) =>
  <TouchableWithoutFeedback onPress={_ => onPress(data##item##id)}>
    <Image
      key={data##item##id}
      source=Image.(
        Source.fromUriSource(
          uriSource(~uri=data##item##urls##small, ~width, ~height=width, ()),
        )
      )
    />
  </TouchableWithoutFeedback>;

[@react.component]
let make = (~data, ~loading as refreshing, ~onPress) => {
  <FlatList
    style={Style.style(~flex=1., ())}
    refreshing
    keyExtractor
    renderItem={renderItem(onPress)}
    data
    numColumns=3
  />;
};