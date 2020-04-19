open Styles;

[@react.component]
let make = (~liked=true) => {
  <Horizontal
    style={
      ViewStyle({
        justifyContent: spaceBetween,
        paddingHorizontal: 12.,
        paddingVertical: 10.,
      })
    }>
    <Horizontal style={ViewStyle({width: 90., justifyContent: spaceBetween})}>
      <Icons.Ionicons
        name={liked ? "md-heart" : "md-heart-empty"}
        size=26
        color={liked ? "#E06666" : "#333"}
      />
      <Icons.EvilIcons name="comment" size=32 color="#333" />
      <Icons.Feather name="send" size=22 color="#777" />
    </Horizontal>
    <Icons.FontAwesome name="bookmark-o" size=24 color="grey" />
  </Horizontal>;
};