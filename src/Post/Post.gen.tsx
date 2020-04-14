/* TypeScript file generated from Post.re by genType. */
/* eslint-disable import/first */


import * as React from 'react';

// tslint:disable-next-line:no-var-requires
const PostBS = require('./Post.bs');

import {route as Navigation_route} from './Navigation.gen';

// tslint:disable-next-line:interface-over-type-literal
export type Props<T1> = { readonly navigation: T1; readonly route: Navigation_route };

export const $$default: React.ComponentType<{ readonly navigation: any; readonly route: Navigation_route }> = PostBS.default;

export default $$default;
