/* TypeScript file generated from Posts.re by genType. */
/* eslint-disable import/first */


import * as React from 'react';

// tslint:disable-next-line:no-var-requires
const PostsBS = require('./Posts.bs');

// tslint:disable-next-line:interface-over-type-literal
export type Props = { readonly id?: string; readonly navigateToPost: (_1:string) => void };

export const $$default: React.ComponentType<{ readonly id?: string; readonly navigateToPost: (_1:string) => void }> = PostsBS.default;

export default $$default;
