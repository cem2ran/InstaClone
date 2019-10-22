let (or) = (a, b) =>
  switch (a) {
  | Some(a') => a'
  | None => b
  };

let bind = (a, andThen) =>
  switch (a) {
  | Some(a') => andThen(a')
  | None => None
  };

let (>>=) = bind;
let (>>>) = Belt.Option.map;

let fold = (option, some, none) => option >>> some or none();

let renderIfTrue = (cond, element) => cond ? element : ReasonReact.null;

let (&) = renderIfTrue;

let renderIfSome = (something, elementFn) =>
  switch (something) {
  | Some(item) => elementFn(item)
  | None => ReasonReact.null
  };

let (&&) = renderIfSome;

let anyOption = Belt.List.some(_, Belt.Option.isSome);
