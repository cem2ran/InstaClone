open ReactNative;

[@react.component]
let make = (~liked=true) => {
  Style.(
    <Horizontal
      style={Style.style(
        ~justifyContent=`spaceBetween,
        ~paddingHorizontal=12.->dp,
        ~paddingVertical=10.->dp,
        (),
      )}>
      <Horizontal
        style={Style.style(~width=90.->dp, ~justifyContent=`spaceBetween, ())}>
        <Icons.Ionicons
          name={liked ? "md-heart" : "md-heart-empty"}
          size=26
          color={liked ? "#E06666" : "#333"}
        />
        <Icons.EvilIcons name="comment" size=32 color="#333" />
        <Icons.Feather name="send" size=22 color="#777" />
      </Horizontal>
      <Icons.FontAwesome name="bookmark-o" size=24 color="grey" />
    </Horizontal>
  );
};
