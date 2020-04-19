include ReactNative.Style;

let center = `center;
let flexStart = `flexStart;
let spaceBetween = `spaceBetween;
let spaceEvenly = `spaceEvenly;
let spaceAround = `spaceAround;

let auto = `auto;
let flexEnd = `flexEnd;
let stretch = `stretch;
let baseline = `baseline;

let none = `none;
let flex = `flex;

let row = `row;
let rowReverse = `rowReverse;
let column = `column;
let columnReverse = `columnReverse;

let absolute = `absolute;
let relative = `relative;

let inherit_ = `inherit_;
let ltr = `ltr;
let rtl = `rtl;

let visible = `visible;
let hidden = `hidden;
let scroll = `scroll;

let solid = `solid;
let dotted = `dotted;
let double = `double;
let dashed = `dashed;

let cover = `cover;
let contain = `contain;
let stretch = `stretch;
let repeat = `repeat;

let uppercase = `uppercase;
let lowercase = `lowercase;
let capitalize = `capitalize;

let underline = `underline;
let lineThrough = `lineThrough;
let underlineLineThrough = `underlineLineThrough;

let left = `left;
let right = `right;
let justify = `justify;

let normal = `normal;
let italic = `italic;
let bold = `bold;
let _100 = `_100;
let _200 = `_200;
let _300 = `_300;
let _400 = `_400;
let _500 = `_500;
let _600 = `_600;
let _700 = `_700;
let _800 = `_800;
let _900 = `_900;

module ViewStyle = {
  let make = ReactNative.Style.viewStyle;
};

module ImageStyle = {
  let make = ReactNative.Style.imageStyle;
};

module TextStyle = {
  let make = ReactNative.Style.textStyle;
};
